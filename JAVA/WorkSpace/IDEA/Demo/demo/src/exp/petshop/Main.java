package exp.petshop;

import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        PetShop petShop = new PetShop();
        System.out.println("欢迎来到宠物商店！\n我们提供以下服务：");
        do {
            petShop.printMenu();
            int choose = input.nextInt();
            switch (choose) {
                case 1: // 寄养宠物
                    System.out.println("您想寄养什么宠物");
                    System.out.println("1.小狗/ 2.小猫/ 3.小鸟 \n 输入序号选择：");
                    int type = input.nextInt();
                    System.out.println("它叫什么名字：");
                    String name = input.next();
                    int number = petShop.getNumber();
                    System.out.println("您的宠物的序号是" + number + "。");
                    switch (type) {
                        case 1 -> petShop.addPet(new Dog(number, name));
                        case 2 -> petShop.addPet(new Cat(number, name));
                        case 3 -> petShop.addPet(new Bird(number, name));
                    }
                    break;
                case 2: // 带走宠物
                    System.out.println("您的宠物叫什么名字：");
                    name = input.next();
                    petShop.removePet(name);
                    break;
                case 3: // 喂养宠物
                    System.out.println("您想喂养哪只宠物呢？\n 名字是：");
                    name = input.next();
                    petShop.feedPet(name);
                    break;
                case 4: // 查看宠物
                    System.out.println("您想看看店里的宠物吗？");
                    System.out.println("1.按类型查看/ 2.按时间查看/ 3.按名称查看");
                    System.out.println("选择：");
                    int choice = input.nextInt();
                    switch (choice) {
                        case 1 -> {
                            System.out.println("您想看什么呢？");
                            System.out.println("1.小狗/ 2.小猫/ 3.小鸟 \n 输入序号选择：");
                            int option = input.nextInt();
                            petShop.viewPetByType(option);
                        }
                        case 2 -> {
                            System.out.println("您要查看几号之前的宠物：");
                            number = input.nextInt();
                            petShop.viewPetByTime(number);
                        }
                        case 3 -> {
                            System.out.println("您想查看哪只宠物呢？");
                            System.out.println("叫什么名字：");
                            name = input.next();
                            petShop.viewPetByName(name);
                        }
                    }
                    break;
                case 5: // 退出程序
                    System.out.println("欢迎下次光临！");
                    return;
                default:
                    System.out.println("抱歉，我们没有该服务。");
                    break;
            }
            System.out.println("您还需要什么服务吗：");
        } while (true);
    }
}
