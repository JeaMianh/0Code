package exp.petshop;

abstract class Pet {
    protected String name;
    protected int number;
    public Pet(int number, String name) {
        this.number = number;
        this.name = name;
    }
    int getNumber() {
        return number;
    }
    String getName() {
        return name;
    }
    abstract void feed();
    static String getType(Pet pet) {
        if (pet instanceof Dog) {
            return "小狗";
        }
        if (pet instanceof Cat) {
            return "小猫";
        }
        if (pet instanceof Bird) {
            return "小鸟";
        }
        return "反正是一只宠物";
    }
    static void showInfo(Pet pet) {
        System.out.println(pet.getNumber() + " 号是一只" + getType(pet) + "，名字叫 " + pet.getName() + "。");
    }
}
class Dog extends Pet {
    public Dog(int number, String name) {
        super(number, name);
    }
    @Override
    void feed() {
        System.out.println(getName() + " 已经吃饱了，发出了汪汪的叫声。");
    }
}
class Cat extends Pet {
    public Cat(int number, String name) {
        super(number, name);
    }
    @Override
    void feed() {
        System.out.println(getName() + " 已经吃饱了，喵喵叫了起来。");
    }
}
class Bird extends Pet {
    public Bird(int number, String name) {
        super(number, name);
    }
    @Override
    void feed() {
        System.out.println(getName() + " 已经吃饱了，唱起了歌。");
    }
}
