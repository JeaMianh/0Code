package exp.petshop;

public class PetShop {
    private int count = 0;
    Pet[] pets= new Pet[10];
    public  int getIndex(String name) {
        if (pets != null) {
            for (Pet pet : pets) {
                if (pet != null && pet.getName().equals(name)) {
                    return pet.getNumber();
                }
            }
        }
        return -1;
    }
    public int getNumber() {
        return count + 1;
    }
    public void printMenu() {
        System.out.println("1.寄养宠物");
        System.out.println("2.带走宠物");
        System.out.println("3.喂养宠物");
        System.out.println("4.查看宠物");
        System.out.println("5.离开商店");
        System.out.println("输入序号进行选择:");
    }

    public void addPet(Pet pet) {
        if (count >= pets.length) {
            System.out.println("店里已经满啦！");
        } else {
            pets[count] = pet; // 将宠物添加到数组中
            count++; // 宠物数量加一
            System.out.println("寄养成功，我们会好好照顾 " + pet.getName() + " 的！");
        }
    }
    public void removePet(String name) {
        int number = getIndex(name);
        if(pets == null) {
            System.out.println("店里没有宠物啊");
        } else if (pets[number - 1] == null) {
            System.out.println("抱歉，店里没有这只宠物");
        } else {
            System.out.println("您可以带走" + pets[number - 1].getName() + "了！");
            pets[number - 1] = null;
            count--;
        }
    }
    public void feedPet(String name) {
        int number = getIndex(name);
        if (number == -1) {
            System.out.println("抱歉，这只宠物不在店里。");
            return;
        }
        if (pets[number - 1] != null) {
            pets[number - 1].feed();
        } else {
            System.out.println("抱歉，这只宠物不在我们这里。");
        }
    }
    public void viewPetByName(String name) {
        int number = getIndex(name);
        if (number == -1) {
            System.out.println("抱歉，这只宠物不在店里。");
            return;
        }
        if (pets[number - 1] != null) {
            Pet.showInfo(pets[number - 1]);
        } else {
            System.out.println("抱歉，我们这里没有这只宠物。");
        }
    }
    public void viewPetByType(int option) {
        String type;
        switch (option) {
            case 1 -> type = "小狗";
            case 2 -> type = "小猫";
            case 3 -> type = "小鸟";
            default -> {
                System.out.println("这是什么宠物？");
                return;
            }
        }
        if (pets != null) {
//            int flag = 0;
            for (Pet pet : pets) {
                int flag = 0;
                if (Pet.getType(pet).equals(type)) {
                    flag = 1;
                    if (pet != null) {
                        Pet.showInfo(pet);
                    }
                } else if (flag == 0){
                    System.out.println("抱歉，店里还没有" + type + "。");
                    break;
                }
            }
        }
    }
    public void viewPetByTime(int number) {
        if (number == 1) {
           System.out.println("前面没有宠物了。");
        } else {
            for (int i = 0; i < number - 1; i++) {
                if(pets[i] != null) {
                    Pet.showInfo(pets[i]);
                }
            }
        }
    }
}

