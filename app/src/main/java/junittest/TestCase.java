package junittest;

public abstract class TestCase  implements  TestInter {
    private String name;
    public TestCase(String name){
        this.name=name;
    }
    @Override
    public void run() {

    }

    public void printResult(boolean isCondition){
        if (isCondition){
            System.out.print("以上是符合该条件的输出信息");
        }else{
            System.out.print("不符合条件的输出信息");
        }
    }
}
