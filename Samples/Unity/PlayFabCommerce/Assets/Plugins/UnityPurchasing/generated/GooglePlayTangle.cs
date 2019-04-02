#if UNITY_ANDROID || UNITY_IPHONE || UNITY_STANDALONE_OSX || UNITY_TVOS
// WARNING: Do not modify! Generated file.

namespace UnityEngine.Purchasing.Security {
    public class GooglePlayTangle
    {
        private static byte[] data = System.Convert.FromBase64String("//4hsH5TfTcJLPE9dDM/6t0QeVYVmXNAO99fiK/UM4Z0bC2CzLnh/xyfkZ6uHJ+UnByfn54bsD3MrIyYWnLhjeCPkgPOnEWTAtxaAz6MjnMSBskQ7C/vNFV8JwpogyidWTUBX8mkQ1XP7Fv0dSaLWxD/UdwNJaEcylWQgiHjZYuMO/pEI4bMQEk6hhes6sbbKyVIEdBXNl8Wp8On8UZch9Ce3zzIPVO4Yol09zz7XpK6Jibb/HetZYNPQOaGdhfnlJciW5Hn1cGrEbFUYPJ9SvdS7xcwTzdAO8FBJ64cn7yuk5iXtBjWGGmTn5+fm56d+iP1J7bTwf3WNHU/TobZmFwae/pYeoMA/v/Zh0ZPjOUfeiwNEpXC2XykyQAGk5StS5ydn56f");
        private static int[] order = new int[] { 2,8,8,3,7,13,10,9,12,10,11,12,13,13,14 };
        private static int key = 158;

        public static readonly bool IsPopulated = true;

        public static byte[] Data() {
        	if (IsPopulated == false)
        		return null;
            return Obfuscator.DeObfuscate(data, order, key);
        }
    }
}
#endif
