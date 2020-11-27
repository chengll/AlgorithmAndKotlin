package us.mifeng.demo.exception;


public class TestException2 {
    private String userName;

    public TestException2(String userName) {
        this.userName = userName;
    }

    public int checkException() throws IlleagalException {
        CustomService customService = new CustomService();
        customService.regiseter(userName);
        return 00;
    }
}
