package us.mifeng.demo.kotlin.chapter5.commonfunction

data class Book(val title:String,val authors:List<String>)
fun main(args: Array<String>) {
    val strings = listOf("abc", "def")
    // println(strings.flatMap { it.toList() })
    val bookList = listOf(Book("Thursday Next", listOf("Jasper Fforde")),
            Book("Mort", listOf("Terry Pratchett")),
            Book("Good Omens", listOf("Terry Pratchett",
                    "Neil Gaiman")))
    //println(bookList.flatMap {element->element.asIterable))
    var list = listOf(listOf(10, 20), listOf(30, 40), listOf(50, 60))
   // val flatList = list.flatMap { it.map { "No.$it + ," } }
}