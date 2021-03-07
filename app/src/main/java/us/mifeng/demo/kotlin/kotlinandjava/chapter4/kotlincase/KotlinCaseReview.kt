package us.mifeng.demo.kotlin.kotlinandjava.chapter4.kotlincase
/**
 * 通过一个案例来熟练kotlin的语法
 * 案例：音乐播放器有系统内置的两种皮肤颜色，每个用户都可以选择自己播放器的皮肤颜色，
 *      当不同的用户登录后，显示不同皮肤颜色的播放器，同时要注意播放器皮肤颜色的可扩展性
 *
 * */
 //用户类 注意：数据类class 常用来模拟java中的javaBean
data class MusicUser(var id:String, var name:String, var playerType:PlayType=PlayType.BLUE)

sealed class PlayType{
    object BLUE:PlayType();
    object GREEN:PlayType();
    //定制一个vip 级别的用户，加入vip可以定制标题和颜色
    class VIP(val title:String?=null,val message:String?=null):PlayType();
}
fun getViewPlayer(type: PlayType)=when(type){
    PlayType.BLUE->BlueViewPlayer ();
    PlayType.GREEN->GreenViewPlayer();
    is PlayType.VIP->PlayType.VIP(type.title,type.message);
}

//写一个单例来实现播放界面
class PlayerUI private constructor(){
    companion object{
        fun getInstance():PlayerUI{
            return Holder.instance;
        }

        private object Holder{
           val instance=PlayerUI();
        }
    }

    fun showPlayer(user:MusicUser){
        MediaPlayerView(getViewPlayer(user.playerType) as PlayerView).showView();
    }
}

interface PlayerView{
    fun getPlayButton();
    fun showView();
}

class MediaPlayerView (playerView:PlayerView):PlayerView by playerView;
//蓝色播放器
class BlueViewPlayer:PlayerView{
    override fun getPlayButton() {
        println("显示器为蓝色的播放器");
    }

    override fun showView() {
       // JoptionPane.showConfirmDialog(null,"显示器为蓝色","蓝色播放器",JoptionPane.DEFAULT_OPTION);
    }
}

//绿色播放器
class GreenViewPlayer :PlayerView{
    override fun getPlayButton() {
      println("显示器为绿色的播放器")
    }

    override fun showView() {
        //JoptionPane.showConfirmDialog(null,"显示器为绿色","绿色播放器",JoptionPane.DEFAULT_OPTION);
    }

}
//vip 播放器
val TITLE="VIP绿色通道"
val MESSAGE="VIP播放器"
class VipPlayer(var title: String?,var name:String?):PlayerView{
    init {
        println("主构造方法");
        title=title?: TITLE;
        name=name?: MESSAGE;
    }

    constructor():this(TITLE, MESSAGE){
        println("无参数构造方法")
    }

    constructor(name:String?):this(MESSAGE,name){
        println("一个参数构造方法");
    }
    override fun getPlayButton() {
        println("Vip Button");
    }

    override fun showView() {
       // JoptionPane.showConfirmDialog(null,name,title,JoptionPane.DEFAULT_OPTION);
    }

}

fun main() {
    val user=MusicUser("01","honey",PlayType.BLUE)
    PlayerUI.getInstance().showPlayer(user);

    //JoptionPane 这个是一个弹框的引入
}