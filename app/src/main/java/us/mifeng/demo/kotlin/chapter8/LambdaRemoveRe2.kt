package us.mifeng.demo.kotlin.chapter8

fun List<SiteVisit>.averageDuration(predicate:(SiteVisit) -> Boolean )=filter(predicate).map(SiteVisit::duration).average();

fun main() {
    println(log.averageDuration{it.os in setOf(OS.ANDROID,OS.IOS)})
    println(log.averageDuration {it.os==OS.IOS  &&  it.path=="signup"})
}

/*
*
* result:
*       12.15
        NaN
* */
