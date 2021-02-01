package us.mifeng.demo.kotlin.chapter11

open class Tag(val name:String){
    private val children = mutableListOf<Tag>()
    protected  fun <T: Tag> doInt(child:T ,init:T.()->Unit){
        child.init();
        children.add(child);
    }

    override fun toString()="<$name> ${children.joinToString ("")}</$name>"
}
//fun table(init: TABLE.() ->Unit) = TABLE().apply(init);