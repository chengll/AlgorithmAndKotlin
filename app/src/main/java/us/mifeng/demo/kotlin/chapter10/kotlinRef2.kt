package us.mifeng.demo.kotlin.chapter10

import java.lang.IllegalArgumentException
import kotlin.reflect.full.primaryConstructor

data class UserDTO1(val id: Int, val login: String,
                    val avatarUrl: String,
                    val url: String,
                    val htmlUrl: String) {

}

data class UserVo(val login: String, val avatalUrl: String)

/*inline fun <reified From : Any, reified To : Any> From.mapAs(): To {
  return From::class.memberProperties.map{it.name to it.get(this)}.toMap().mapAs();
}*/

inline fun <reified To:Any>Map<String,Any>.mapAs():To{
    return To::class.primaryConstructor!!.let {
        it.parameters.map{
            parameter ->
            parameter to(this[parameter.name]?:if (parameter.type.isMarkedNullable) null
            else throw IllegalArgumentException("${parameter.name}is required but missing"))
        }.toMap()
                .let (it::callBy)
    }
}


fun main() {
    val userDTO = UserDTO1(0, "honey",
            "https://www.baidu.com/link?url=-i0Qi6W2Non8n32ZMoSG0VNP-TYFR018j3CN78EPkbTabC6OlvHnmp7AeAtAx0nB7yPbDT-fDHPgiI_XFK9bvRwkXtC2auGHCCgUU6SQj-0vQOa3t-nd4VFzo--K41CMUS834qo-_Y3BstDNFI9qGyVu83OTfID7L-y-yEZLm1oC6eC8DuHioNlxRrUboonroIhAj9ysu4BAztM17_S8wVxbAgXM05rOc1LhAXOJOPrhGbgKL53Q1_ItK33QljHAqTwm7rBdwauxw1vMsb3Bc3BaPGoAemy8yzWB8jiSd_Vg4-zf2XT2q3lHmH34A4MpqYScbBWcYuanXyRikFoPpnue0YzslbMZlWp9IegsAN6bJB_1XJiqyoiD9yRzwwsYnP2G2hLQdjo_0B8JPOjVb6tHUD89NcNseA0431-EVsfd0yGfFR18lql69NwheoMobml1UOhIqo1DO6ZTU_cgjLwlNlnm5s4zXHtgGqmCrUD-wdUzM5yGlhYPOJ5hd5T0Ysokw-2Hf_nz9_Shcl0QClyl-KB9uo6G4Y263W4R5ynOoszsuPQ0cBffTPHfnF-OLFqAXGYxJQnK8-BTpP6-b_&click_t=1610954798458&s_info=1263_578&wd=&eqid=bbdfc5b0000be585000000036005382a",
            "https://www.baidu.com/link?url=-i0Qi6W2Non8n32ZMoSG0VNP-TYFR018j3CN78EPkbTabC6OlvHnmp7AeAtAx0nB7yPbDT-fDHPgiI_XFK9bvRwkXtC2auGHCCgUU6SQj-0vQOa3t-nd4VFzo--K41CMUS834qo-_Y3BstDNFI9qGyVu83OTfID7L-y-yEZLm1oC6eC8DuHioNlxRrUboonroIhAj9ysu4BAztM17_S8wVxbAgXM05rOc1LhAXOJOPrhGbgKL53Q1_ItK33QljHAqTwm7rBdwauxw1vMsb3Bc3BaPGoAemy8yzWB8jiSd_Vg4-zf2XT2q3lHmH34A4MpqYScbBWcYuanXyRikFoPpnue0YzslbMZlWp9IegsAN6bJB_1XJiqyoiD9yRzwwsYnP2G2hLQdjo_0B8JPOjVb6tHUD89NcNseA0431-EVsfd0yGfFR18lql69NwheoMobml1UOhIqo1DO6ZTU_cgjLwlNlnm5s4zXHtgGqmCrUD-wdUzM5yGlhYPOJ5hd5T0Ysokw-2Hf_nz9_Shcl0QClyl-KB9uo6G4Y263W4R5ynOoszsuPQ0cBffTPHfnF-OLFqAXGYxJQnK8-BTpP6-b_&click_t=1610954798458&s_info=1263_578&wd=&eqid=bbdfc5b0000be585000000036005382a",
            "https://www.baidu.com/link?url=-i0Qi6W2Non8n32ZMoSG0VNP-TYFR018j3CN78EPkbTabC6OlvHnmp7AeAtAx0nB7yPbDT-fDHPgiI_XFK9bvRwkXtC2auGHCCgUU6SQj-0vQOa3t-nd4VFzo--K41CMUS834qo-_Y3BstDNFI9qGyVu83OTfID7L-y-yEZLm1oC6eC8DuHioNlxRrUboonroIhAj9ysu4BAztM17_S8wVxbAgXM05rOc1LhAXOJOPrhGbgKL53Q1_ItK33QljHAqTwm7rBdwauxw1vMsb3Bc3BaPGoAemy8yzWB8jiSd_Vg4-zf2XT2q3lHmH34A4MpqYScbBWcYuanXyRikFoPpnue0YzslbMZlWp9IegsAN6bJB_1XJiqyoiD9yRzwwsYnP2G2hLQdjo_0B8JPOjVb6tHUD89NcNseA0431-EVsfd0yGfFR18lql69NwheoMobml1UOhIqo1DO6ZTU_cgjLwlNlnm5s4zXHtgGqmCrUD-wdUzM5yGlhYPOJ5hd5T0Ysokw-2Hf_nz9_Shcl0QClyl-KB9uo6G4Y263W4R5ynOoszsuPQ0cBffTPHfnF-OLFqAXGYxJQnK8-BTpP6-b_&click_t=1610954798458&s_info=1263_578&wd=&eqid=bbdfc5b0000be585000000036005382a"
    )
    //val userVo: UserVo = userDTO.mapAs();
    val userMap = mapOf("id" to 0, "login" to "honey", "avatarUrl" to "https://www.baidu.coom", "url" to "https://github.com")
    val userVoFromMap: UserVo = userMap.mapAs();
    println(userVoFromMap)


}