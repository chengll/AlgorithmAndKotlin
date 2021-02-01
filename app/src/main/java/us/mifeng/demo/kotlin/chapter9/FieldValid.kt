package us.mifeng.demo.kotlin.chapter9

import java.lang.IllegalArgumentException
import kotlin.reflect.KClass

interface FieldValidation<in T> {
    fun validate(input: T): Boolean;
}

object DefaultStringValidator : FieldValidation<String> {
    override fun validate(input: String) = input.isEmpty();
}

object DefaultIntValidator : FieldValidation<Int> {
    override fun validate(input: Int) = input > 0
}

object Validatorr {
    private val validators = mutableMapOf<KClass<*>, FieldValidation<*>>();
    fun <T : Any> registerValidator(KClass: KClass<T>, fieldValidator: FieldValidation<T>) {
        validators[KClass] = fieldValidator;
    }

    operator fun <T : Any> get(kClass: KClass<T>): FieldValidation<T> =
            validators[kClass] as? FieldValidation<T>
                    ?: throw IllegalArgumentException("no validator for ${kClass.simpleName}")
}

fun main() {
    Validatorr.registerValidator(String::class,DefaultStringValidator)
    Validatorr.registerValidator(Int::class,DefaultIntValidator);
    println(Validatorr[String::class].validate("Kotlin"));
    println(Validatorr[Int::class].validate(42))
}
/*
* result:
*       false
        true
*
* */