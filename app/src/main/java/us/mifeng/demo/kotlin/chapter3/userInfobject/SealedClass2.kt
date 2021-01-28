package us.mifeng.demo.kotlin.chapter3.userInfobject

//优化类SealedClass1.kt
sealed class Expr2 {
    class Num(val value: Int) : Expr2()
    class Sum(val left: Expr2, val right: Expr2) : Expr2()
}

fun eval(e:Expr2):Int=when(e){
    is Expr2.Num->e.value
    is Expr2.Sum -> eval(e.left) + eval(e.right)
}