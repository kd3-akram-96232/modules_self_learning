using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace cdac_dotnet
{

//#nullable enable
    class Box
    {
        int? Name { get; set; }
        int Email { get; set; }
    }
    internal class Learning2
    {
        static void Main(string[] args)
        {

            #region Null Handling
            //int? nullableInt = 20;

            //Console.WriteLine(nullableInt ?? 10);

            //List<string> list = new List<string>();
            //list = null;
            //list?.Add("Akram");
            //list?.Add("Akram");
            //list?.Add("Akram");

            //string getString()
            //{
            //    return "Hello world";
            //}

            //int? value = null;
            // value ??= "Initialised"; // it is not support in 7.3 you use 8.0 to greater version

            // string newVal = getString()!; // it is also not support in 7.3; > 8
            
            #endregion
        }
    }
}
