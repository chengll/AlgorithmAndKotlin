package us.mifeng.demo.kotlin.chapter3.userInfobject

import java.lang.IllegalArgumentException

class User(val id: Int, val name: String, val address: String)

fun User.validateBeforeSave() {
    fun validate(value: String, fileName: String) {
        if (value.isEmpty()) {
            throw IllegalArgumentException("can not find $id,empty $fileName")
        }
    }
    validate(name, "Name");
    validate(address, "Address");
}

fun saveUser(user: User) {
    user.validateBeforeSave();
}
fun main() {
    saveUser(User(1,"dsgds ","sdgsgg"));
}

/**
 *  result:如果name 和address传空时 会抛出异常
 *        如果不为空，则保存数据成功
 * */