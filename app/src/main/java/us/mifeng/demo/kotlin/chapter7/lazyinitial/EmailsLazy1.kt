package us.mifeng.demo.kotlin.chapter7.lazyinitial

class Email {}

fun loadEmails(personEmail: PersonEmail): List<Email> {
    println("load email for ${personEmail.name}")
    return listOf(Email());
}

class PersonEmail(val name: String) {
    //第二🀄种延迟加载的方式
    val emailsInfoList by lazy { loadEmails(this) }
    //1.第一种延迟加载的方法
    private var emails_list: List<Email>? = null;
    val emails: List<Email>
        get() {
            if (null == emails_list) {
                emails_list = loadEmails(this)
            }
            return emails_list!!;
        }
}



fun main() {
    val p=PersonEmail("honey");
    p.emails;
    p.name;
}

/*
*  result:
*   load email for honey
*
* */