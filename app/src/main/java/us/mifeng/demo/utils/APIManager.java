package us.mifeng.demo.utils;

import java.io.InputStream;
import java.security.KeyStore;
import java.security.NoSuchAlgorithmException;
import java.security.cert.CertificateException;
import java.security.cert.CertificateFactory;
import java.security.cert.X509Certificate;

import javax.net.ssl.SSLContext;
import javax.net.ssl.TrustManager;
import javax.net.ssl.TrustManagerFactory;
import javax.net.ssl.X509TrustManager;
import javax.security.cert.Certificate;

/**
 * 给okHttps添加https证书
 * */
public class APIManager {
     private static String CER_STR="private static final String CER_YILIAN = \"-----BEGIN CERTIFICATE-----\\n\" +\n" +
             "            \"MIIFqjCCBJKgAwIBAgIQBx+15z+1utfoVQez3qb4ADANBgkqhkiG9w0BAQsFADBe\\n\" +\n" +
             "           \"MQswCQ\"Fw0xODA0MDkwMDAwMDBaFw0xOTA0MDkxMjAwMDBaMBUxEzARBgNVBAMMCioudXBs\\n\" +\n" +
             "            \"b28uYTFJTQUNBMjAxOC5jcmwwTAYDVR0gBEUwQzA3\\n\" +\n" +
             "            \n" +
             "            \"AjAAMIIBAwYKKwYBBAHWeQIEAgSB9ASB8QDvAHUApLkJkLQYWBSHuxOizGdwCjw1\\n\" +\n" +
             "            \n" +
             "            \"oSFEWyxDmV8NodSm2JLEsRppc7i4vTrchPS/75EkXS+AMKfNyrRDw4u0uS1+EZMl\\n\" +\n" +
             "            \"P6Nl0JkGq1BJpvPhWCs=\\n\" +\n" +
             "            \"-----END CERTIFICATE-----\\n\" +\n" +
             "            \"-----BEGIN CERTIFICATE-----\\n\" +";

    public static TrustManager[] createTrustManager(InputStream... inputStream){
        if (inputStream.length==0 || inputStream.equals("")){
            return  null;
        }

        try {
            CertificateFactory certificateFactory=CertificateFactory.getInstance(CER_STR);
            KeyStore keyStore=KeyStore.getInstance(KeyStore.getDefaultType());
            keyStore.load(null);

            int  index=0;
            for(InputStream certificate:inputStream) {
                String certificateAlias = Integer.toString(index++);
                keyStore.setCertificateEntry(certificateAlias,certificateFactory.generateCertificate(certificate));
            }

            TrustManagerFactory trustManagerFactory=TrustManagerFactory.getInstance(TrustManagerFactory.getDefaultAlgorithm());
            trustManagerFactory.init(keyStore);
            X509TrustManager  x509TrustManager=new X509TrustManager() {
                @Override
                public void checkClientTrusted(X509Certificate[] chain, String authType) throws CertificateException {

                }

                @Override
                public void checkServerTrusted(X509Certificate[] chain, String authType) throws CertificateException {

                }

                @Override
                public X509Certificate[] getAcceptedIssuers() {
                    return new X509Certificate[0];
                }
            };

            return trustManagerFactory.getTrustManagers();

        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }


   /* private static HttpsUtil.SSLParam getSslSocketFactory(InputStream... inputStreams) {
        HttpsUtil.SSLParam  httpsSSLParam=new HttpsUtil.SSLParam();
        TrustManager[] trustManagers=createTrustManager(inputStreams);
        try {
            SSLContext sslContext = SSLContext.getInstance("TLS");
            for (TrustManager mTrustManager:trustManagers){

            }
        } catch (Exception e) {
            e.printStackTrace();
        }

        return null;
    }*/


}
