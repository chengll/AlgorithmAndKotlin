package us.mifeng.demo.kotlin.chapter9

fun<T: Number> oneHalf(value: T) :Double{
    return  value.toDouble()/2.0;
}

fun <T:Comparable<T>>  max(first:T, second:T) :T{
    return if (first >second) first else second
}

fun <T>  ensureTrailingPerid(seq:T)
     where T:CharSequence, T:Appendable{
    if (!seq.startsWith('.')){
        seq.append('.');
    }
}


fun main() {
    println(oneHalf(3));
    println(max("kotlin","java"));

    val helloWorld=StringBuilder("Hello world");
    ensureTrailingPerid(helloWorld);
    println(helloWorld);
}
/*
* result:
*            1.5
*           kotlin
*           Hello world.
* */