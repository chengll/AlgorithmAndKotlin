package us.mifeng.demo.kotlin.chapter7

import java.beans.PropertyChangeListener
import java.beans.PropertyChangeSupport
import kotlin.reflect.KProperty

open class PropertyChangeAware{
    protected val changeSupport=PropertyChangeSupport(this);

    fun addPropertyListener(listener:PropertyChangeListener){
        changeSupport.addPropertyChangeListener(listener);
    }

    fun removePropetyChangeListener(listener: PropertyChangeListener){
        changeSupport.removePropertyChangeListener(listener);
    }
}

class PersonChange(val name:String, age:Int, salary:Int):PropertyChangeAware(){
    var age:Int=age;
    var salary=salary;
    /*set(newValue){
        val oldValue=field;
        field=newValue;
        changeSupport.firePropertyChange("age",oldValue,newValue)
    }
    var salary:Int=salary;
    set(newValue){
        val oldValue=field;
        field=newValue;
        changeSupport.firePropertyChange("salary",oldValue,newValue);
    }*/
}


fun main() {
    val p=PersonChange("Dimitry",12,34);
    p.addPropertyListener(PropertyChangeListener {
        event->
        println("Property ${event.propertyName} changed from ${event.oldValue} to  ${event.newValue}")
    })
    p.age=23;
    p.salary=45
}