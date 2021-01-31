package us.mifeng.demo.kotlin.chapter7

import android.security.keystore.KeyProperties
import java.beans.PropertyChangeListener
import kotlin.properties.Delegates
import kotlin.reflect.KProperty

class PersonDele(val name:String,age:Int,salary:Int):PropertyChangeAware(){
    private  val observer={
        prop: KProperty<*>,oldValue:Int,newValue:Int ->
        changeSupport.firePropertyChange(prop.name,oldValue,newValue);
    }
    var age:Int by Delegates.observable(age,observer);
    var salary:Int by Delegates.observable(salary,observer);
}

fun main() {
    val p=PersonDele("honey",18,233);
    p.addPropertyListener(PropertyChangeListener {
        event->
        println("Propery ${event.propertyName} changed from ${event.oldValue} to ${event.newValue}")
    })
    p.age=19;
    p.salary=324
}

/*
* result:
*   Propery age changed from 18 to 19
    Propery salary changed from 233 to 324
* */