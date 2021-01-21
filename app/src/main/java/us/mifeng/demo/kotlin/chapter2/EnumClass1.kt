package us.mifeng.demo.kotlin.chapter2

// 枚举类和when表达式的混合使用
enum class Color {
    RED, ORAGNE, YELLOW, GREEN, BLUE, INDIGO, VIOLET
}

fun getMnemonic(color: Color) =
        when (color) {
            Color.RED -> "Richard"
            Color.ORAGNE -> "of"
            Color.YELLOW -> "york"
            Color.GREEN -> "Gave"
            Color.BLUE -> "Battle"
            Color.INDIGO -> "in"
            Color.VIOLET -> "Vain"
        }

fun mix(c1: Color, c2: Color) = when (setOf(c1, c2)) {
    setOf(Color.YELLOW, Color.BLUE) -> Color.YELLOW
    setOf(Color.YELLOW, Color.BLUE) -> Color.GREEN
    setOf(Color.BLUE, Color.VIOLET) -> Color.INDIGO
    else -> throw Exception("Dirty color")
}

fun main(args: Array<String>) {
    println(getMnemonic(Color.BLUE))
    println(mix(Color.BLUE,Color.VIOLET));
}

    /*
    result:
    Battle
    INDIGO
    */
