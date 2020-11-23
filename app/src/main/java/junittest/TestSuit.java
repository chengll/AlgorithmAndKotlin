package junittest;

import java.util.Enumeration;
import java.util.Vector;

public class TestSuit extends TestCase {
    private String name;
    private Vector tests=new Vector();
    public TestSuit(String name) {
        super(name);
    }

    @Override
    public void run() {
        for (Enumeration e=tests.elements();e.hasMoreElements();){
            TestInter testInter= (TestInter) e.nextElement();
            testInter.run();
        }
    }
    //将执行完的用例加入集合中
    public void addTests(TestInter test){
        tests.add(test);
    }
}
