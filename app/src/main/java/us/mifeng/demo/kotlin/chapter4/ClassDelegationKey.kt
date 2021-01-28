package us.mifeng.demo.kotlin.chapter4

class CountingSet<T>(val innerSet: MutableCollection<T> = HashSet<T>()) : MutableCollection<T> by innerSet {
    var objectAdded = 0
    override fun add(element: T): Boolean {
        objectAdded++;
        return innerSet.add(element);
    }

    override fun addAll(c: Collection<T>): Boolean {
        objectAdded += c.size
        return innerSet.addAll(c);
    }
}

fun main() {
    val cSet= CountingSet<Int>();
    cSet.addAll(listOf(1,1,2))
    println(" ${cSet.objectAdded} objects were added, ${cSet.size} remain")
}


/*
*
* result:  3 objects were added, 2 remain
* */
