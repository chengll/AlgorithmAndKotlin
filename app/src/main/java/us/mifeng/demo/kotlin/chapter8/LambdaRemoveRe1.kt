package us.mifeng.demo.kotlin.chapter8


data class SiteVisit(
        val path: String,
        val duration: Double,
        val os: OS)

enum class OS { WINDOWS, MAC, LINUX, IOS, ANDROID }

val log = listOf(
        SiteVisit("/", 34.0, OS.WINDOWS),
        SiteVisit("/", 22.0, OS.MAC),
        SiteVisit("/login", 12.0, OS.WINDOWS),
        SiteVisit("/signup", 8.0, OS.IOS),
        SiteVisit("/", 16.3, OS.ANDROID)
)
val averageWindowDuration = log.filter {
    it.os == OS.WINDOWS
    }.map(SiteVisit::duration).average()

fun List<SiteVisit>.averageDuration(os:OS)=filter{it.os==os}.map ( SiteVisit::duration ).average()

fun main() {
    println(averageWindowDuration )
    println(log.averageDuration(OS.WINDOWS))
    println(log.averageDuration(OS.MAC))
}
/*
* result:
*   23.0
    23.0
    22.0
*
* */