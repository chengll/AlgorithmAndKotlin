package us.mifeng.demo.kotlin.chapter2.trycatchexp

import java.io.BufferedReader
import java.io.StringReader

fun readNumber(reader: BufferedReader): Int? {
    try {
        val line = reader.readLine();
        return Integer.parseInt(line);
    } catch (e: Exception) {
        return null;
    } finally {
        reader.close();
    }
}

fun readerNum2(reader: BufferedReader) {
    val number = try {
        Integer.parseInt(reader.readLine());
    } catch (e:Exception) {
        return;
    }
    println(number);
}

fun main() {
    val reader1 = BufferedReader(StringReader("12"));
    println(readNumber(reader1));

    val reader = BufferedReader(StringReader("129jjh"))
    println(readNumber(reader))

    val reader2=BufferedReader(StringReader("23"));
    readerNum2(reader2);
}
/*
* result:
*   12
    null
    23
* */