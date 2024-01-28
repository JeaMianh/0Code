#include <stdio.h>
#include <string.h>

FILE *inputFile, *outputFile;

int encode(unsigned char *inputByte, unsigned char *outputByte) {
    unsigned char *in = inputByte, *out = outputByte;
    int left = strlen(inputByte), size = 0;
    while(left > 0) {
        if (left < 3) {
            out[size++] = *in++;
            left--;
        } else if(in[0] == in[1] && in[1] == in[2]) {
            int i = 0, len = 1;
            while(i < left - 1 && len < 127) {
                if (in[i] == in[i+1]) {
                    len++;
                    i++;
                } else {
                    break;
                }
            }
            out[size++] = len | 0x80;
            out[size++] = *in;
            in += len;
            left -= len;
        } else {
            out[size++] = *in++;
            left--;
        }  
    }
    return size;
}
int decode(unsigned char *inputByte, unsigned char *outputByte) {
    unsigned char *in = inputByte, *out = outputByte;
    int i = 0, size = 0;
    while (i < strlen(inputByte)) {
        if((in[i] & 0x80) == 0x80) {
            int c = in[i] & 0x7f;
            i++;
            while(c--) {
                out[size++] = in[i];
            }
            i++;
        } else {
            out[size++] = in[i++];
        }
    }
    return size;
}

int main(int argc, char *argv[4]) {
    inputFile = fopen(argv[1], "rb");
    outputFile = fopen(argv[3], "wb");
    if (inputFile == NULL || outputFile == NULL) {
        fclose(inputFile);
        fclose(outputFile);
        printf("Can't find the file\n");
        return 0;
    }

    unsigned char *inputByte = (unsigned char*) malloc (sizeof(unsigned char)*1024*1024);
    unsigned char *outputByte = (unsigned char*) malloc (sizeof(unsigned char)*1024*1024);
    if (strcmp(argv[2],"-c") == 0) {
        while(fread(inputByte, sizeof(unsigned char), 1024, inputFile) != 0){
            int size = encode(inputByte, outputByte);
            fwrite(outputByte, sizeof(unsigned char), size, outputFile);
        }
        printf("Compress successfully!\n");
    } else if (strcmp(argv[2],"-d") == 0) {
        while(fread(inputByte, sizeof(unsigned char), 1024, inputFile) != 0){
            int size = decode(inputByte, outputByte);
            fwrite(outputByte, sizeof(unsigned char), size, outputFile);
        }
        printf("Decompress successfully!\n");
    }

    fclose(inputFile);
    fclose(outputFile);
    
    return 0;
}