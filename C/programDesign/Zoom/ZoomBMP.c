#include <stdio.h>
#include <stdlib.h>	// atof,atoi,malloc
// #pragma pack(1)

// 文件信息头结构体
typedef struct BITMAP_FILE_HEADER {
    unsigned short bitmapType;      // 决定文件类型，值为19778时即为bmp格式文件
    unsigned int bitmapSize;        // 整个bmp文件的大小，单位为字节
    unsigned short bitmapReserved1; // 保留字，必须设置为0
	unsigned short bitmapReserved2; // 同上
    unsigned int bitmapOffsets;     // 实际位图数据的偏移字节数，即文件信息到颜色表的长度之和
} FILEHEADER;

// 图片描述信息结构体
typedef struct BITMAP_INFO_HEADER {
    unsigned int bitmapSize;         // 图片描述信息结构体的大小，40字节
    long bitmapWidth;                // 图像的宽
	long bitmapHeight;               // 图像的高
    unsigned short bitmapPlane;     // 位图所在平面，显示器只有一个平面，所以恒等为1
    unsigned short  bitmapBitCount;  // 一像素所占的位数，一般为24，也就是三个字节
    unsigned int bitCompression;     // 说明图像数据压缩的类型，0为不压缩
    unsigned int bitSizeImage;       // 像素数据所占大小，等于上面文件头结构中bitmapSize-bitmapOffsets
	long bitXPelsPerMeter;           // 说明水平分辨率，用像素米表示。一般为0
	long bitYPelsPerMeter;           // 说明垂直分辨率，用像素米表示。一般为0
	unsigned int bitColourUsed;      // 说明位图实际使用的彩色表中的颜色索引数（设为0的话，则说明使用所有调色板项）
	unsigned int bitColourImportant; // 说明对图象显示有重要影响的颜色索引的数目，如果是0，表示都重要
} INFOHEADER;

// RGB_QUAD 颜色表，这里采用24位色彩，故没有这部分信息

//文件信息头
FILEHEADER inputFile;
FILEHEADER outputFile;
//图像描述信息
INFOHEADER inputInfo;
INFOHEADER outputInfo;
//图像每行占用的字节数
long inputLineByteSize;
long outputLineByteSize;
//储存目标文件的所有像素点数据
unsigned char *inputData;
unsigned char *outputData;

// 读取初始文件
void LoadBMP(const char *input) {
    // 打开文件，如果不存在，就报错退出
    FILE *fp = fopen(input, "rb"); 
    if (fp == 0) {
        printf("Open failed\n");
        return;
    }

    fseek(fp,sizeof(FILEHEADER),0); 

    //如果文件样式不满足要求，直接退出
	fseek(fp, 0, 0); 
	fread(&inputFile, sizeof(FILEHEADER), 1, fp);
	if (inputFile.bitmapType != 19778) {
		printf("Not a legal pic file\n");
		return;
	}

    //读取图像信息，并根据文件头文件里图像大小信息和偏移信息(图像文件头信息，图片信息和调色板)来得出数据区大小
    fread(&inputInfo, sizeof(INFOHEADER), 1, fp);
	inputData = (unsigned char *)malloc(inputFile.bitmapSize - inputFile.bitmapOffsets);
	fread(inputData, inputFile.bitmapSize - inputFile.bitmapOffsets, 1, fp); 
}

void SaveBMP(char *output) {
    FILE *file = fopen(output, "wb");
    if(file == 0) {
        printf("Save failed");
        return;
    }

    // 写入文件信息头
    outputFile.bitmapType = 19778;
	outputFile.bitmapSize = sizeof(FILEHEADER) + sizeof(INFOHEADER) + outputLineByteSize * outputInfo.bitmapHeight;
	outputFile.bitmapReserved1 = 0;
	outputFile.bitmapReserved2 = 0;
	outputFile.bitmapOffsets = sizeof(FILEHEADER) + sizeof(INFOHEADER);
    // 写入图像描述信息
    outputInfo.bitmapSize = sizeof(INFOHEADER);
	outputInfo.bitmapPlane = inputInfo.bitmapPlane;
	outputInfo.bitCompression = inputInfo.bitCompression;
	outputInfo.bitSizeImage = outputLineByteSize * outputInfo.bitmapHeight;
	outputInfo.bitXPelsPerMeter = inputInfo.bitXPelsPerMeter;
	outputInfo.bitYPelsPerMeter = inputInfo.bitYPelsPerMeter;
	outputInfo.bitColourUsed = inputInfo.bitColourUsed;
	outputInfo.bitColourImportant = inputInfo.bitColourImportant;
    
    //写入到新生成的文件
	fwrite(&outputFile, sizeof(FILEHEADER), 1, file);
	fwrite(&outputInfo, sizeof(INFOHEADER), 1, file);
	fwrite(outputData, outputInfo.bitSizeImage, 1, file);
	
	//收尾工作，关闭文件，释放内存
	free(outputData);
	fclose(file);
	printf("Zoom successfully");
	return;
}

void Zoom(const char *ratio) {
	//计算新生成图像像素，长宽信息，每行有几个像素，并为新图片像素信息分配内存地址
	float zoomnumber = atof(ratio) * 1.0 / 100.0;
	outputInfo.bitmapBitCount = inputInfo.bitmapBitCount;
	outputInfo.bitmapWidth = (int)(inputInfo.bitmapWidth * zoomnumber + 0.5);
	outputInfo.bitmapHeight = (int)(inputInfo.bitmapHeight * zoomnumber + 0.5);
	inputLineByteSize = (inputInfo.bitmapWidth * outputInfo.bitmapBitCount + 31 ) / 32 * 4;
	outputLineByteSize = (outputInfo.bitmapWidth * inputInfo.bitmapBitCount + 31 ) / 32 * 4;
	outputData = (unsigned char *)malloc(sizeof(unsigned char) * outputLineByteSize * outputInfo.bitmapHeight);

	//使用双线性插值法缩放图像，公式如下
	//f(x,y) = f(Q11)(x2-x)(y2-y) + f(Q21)(x-x1)(y2-y) + f(Q12)(x2-x)(y-y1) + f(Q22)(x-x1)(y-y1)
	//其中x,y为要取得的点，Q11,Q12,Q21,Q22为取的四个临近点
 	//BMP像素的存储顺序为从左到右，从下到上
	for (int i = 0; i < outputInfo.bitmapHeight; i++) {
		for (int j = 0; j < outputInfo.bitmapWidth; j++) {
			//每个像素有三个颜色数据，也就是能增强电脑性能的RGB三色
			for (int k = 0; k < 3; k++) {
				//先定位一个点
				int i1 = i / zoomnumber;
				int j1 = j / zoomnumber;
				//再找其他两个点
				int i2 = i1 + 1;
				int j2 = j1 + 1;
				//计算需要的数据
				double fx1 = i1 - i1;
				double fx2 = 1.0 - fx1;
				double fy1 = j1 - j1;
				double fy2 = 1.0 - fy1;
				
				double s1 = fx1 * fy1;
				double s2 = (1.0 - fx1) * fy1;
				double s3 = (1.0 - fx1) * (1.0 - fy1);
				double s4 = fx1 * (1.0 - fy1);
				//现在往目标图像数据中写入插值得到的数据
				if ((j1 >= 0) && (j1 < inputInfo.bitmapWidth - 1) && (i1 >= 0) && (i1 < inputInfo.bitmapHeight - 1)) {
					*(outputData + i * outputLineByteSize + j * 3 + k)
				  = *(inputData + i2 * inputLineByteSize + j2 * 3 + k) * s1
			      + *(inputData + i1 * inputLineByteSize + j2 * 3 + k) * s2
			      + *(inputData + i1 * inputLineByteSize + j1 * 3 + k) * s3
				  + *(inputData + i2 * inputLineByteSize + j1 * 3 + k) * s4;
				} else {
					*(outputData + i * outputLineByteSize + j * 3 + k) = 255;
				}
			}
		}
	}
	//释放输入图片的内存
	free(inputData);
}

int main(int argc, char *argv[4]) {
    LoadBMP(argv[1]);
    Zoom(argv[2]);
    SaveBMP(argv[3]);
    return 0;
}