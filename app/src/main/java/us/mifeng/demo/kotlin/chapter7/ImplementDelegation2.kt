package us.mifeng.demo.kotlin.chapter7

import java.beans.PropertyChangeListener
import java.beans.PropertyChangeSupport
import kotlin.properties.Delegates
import kotlin.reflect.KProperty

class ObservableProperty(var propValue:Int, val changeSupport: PropertyChangeSupport){
    operator fun getValue(p:ObservablePerson,prop: KProperty<*>):Int=propValue;
    operator fun setValue(p:ObservablePerson, prop: KProperty<*>, newValue:Int){
        val oldValue=propValue;
        propValue=newValue;
        changeSupport.firePropertyChange(prop.name,oldValue, newValue)
    }
}

class ObservablePerson(val name:String,age:Int,salary:Int):PropertyChangeAware(){
    var age:Int by ObservableProperty(age,changeSupport);
    var salary:Int by ObservableProperty(salary,changeSupport);
}

fun main() {
    val p=ObservablePerson("Ditory",21,34);
    p.addPropertyListener(PropertyChangeListener {
        event ->
        println("property ${event.propertyName} from ${event.oldValue} to ${event.newValue}")
    })
    p.age=21
    p.salary=45
}

/*
*  result:
*   property salary from 34 to 45
*
* */