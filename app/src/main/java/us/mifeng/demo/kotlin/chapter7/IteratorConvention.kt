package us.mifeng.demo.kotlin.chapter7

import android.os.Build
import androidx.annotation.RequiresApi
import java.time.LocalDate

operator fun ClosedRange<LocalDate>.iterator():Iterator<LocalDate>{
    return object : Iterator<LocalDate> {
        var current = start;
        override fun hasNext() = current <= endInclusive
        @RequiresApi(Build.VERSION_CODES.O)
        override fun next() = current.apply {
            current = plusDays(1);
        }
    }
}

@RequiresApi(Build.VERSION_CODES.O)
fun main() {
    val newYear=LocalDate.ofYearDay(2017,1);
    val dayOff=newYear.minusDays(1)..newYear;
    for (dayOf in dayOff){
        println(dayOf);
    }
}

/*
*result:
*   2016-12-31
    2017-01-01
*
* */