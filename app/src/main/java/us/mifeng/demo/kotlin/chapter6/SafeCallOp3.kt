package us.mifeng.demo.kotlin.chapter6
class Address(val streetAddress: String,val zipCode:Int,val city:String ,val country:String)
class Company(val name:String,val address:Address?)
class PersonCity(val name:String,val company:Company?)

fun PersonCity.countryName():String{
    val country=this.company?.address?.country;
    return if(country!=null)country else "Unknow";
}

fun main() {
    val person=PersonCity("honey",null);
    println(person.countryName())
    val person2=PersonCity("honey", Company("bjkeji", Address("chaoyaong",123,"北京","北京朝阳")));
    println(person2.countryName());

}

/* result:  Unknow
        北京朝阳
*
* */