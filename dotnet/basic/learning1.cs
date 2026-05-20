


using System;

namespace cdac_dotnet
{

    class MyClass
    {
        public int X { get; set; }
    }

    internal class Learning1
    {

        static async Task Main(string[] args)
        {

            #region numeric literals
            //int dec = 42;
            //int hex = 0x2a;
            //int binary = 0b101010;
            //int withUnderscores = 1_000_000;

            //Console.WriteLine(dec);
            //Console.WriteLine(hex);
            //Console.WriteLine(binary);
            //Console.WriteLine(withUnderscores);

            #endregion

            #region string literals

            //            string regular = "Hello\nWorld";
            //            string Verbatim = @"C:/User/Home";
            //            string interpolated = $"value: {10}";
            //            string multiline = @"
            //                Line 1
            //Line 2 Line 3
            //            ";

            //            Console.WriteLine(regular);
            //            Console.WriteLine(Verbatim);
            //            Console.WriteLine(interpolated);
            //            Console.WriteLine(multiline);

            #endregion

            #region
            //object ob = "Hello";
            //string str = ob as string;
            //string str2 = str.Replace('H', 'J');
            //Console.Write(str2);
            //bool isStr = ob is int;
            //if (isStr)
            //{
            //    string st3 = (string) ob;
            //}

            //object a = 10;
            //bool b = a is string;

            //string abc = "1000";
            //Console.WriteLine(nameof(System));

            #endregion

            #region Implicit/Explicit Type conversion (no data loss, automatic)
            //long longNum = 10232020;
            //try
            //{
            //    // its throw error for integer out of bound value
            //    int smallNum2 =  Convert.ToInt32(longNum);

            //}catch(OverflowException ex)
            //{
            //    Console.WriteLine("not converted");
            //}
            //int smallNum3 = (int) longNum;
            //Console.WriteLine("long num: " + longNum);
            //Console.WriteLine("small num 2: " + smallNum2);
            //Console.WriteLine("small num 3: " + smallNum3);

            //long large = 1_000_000_000_000;
            // by default it is unchecked.
            // checked means if it is overflow than give error not behave like circular linked list
            //checked
            //{
            //int small = (int)large;
            //Console.WriteLine(small);
            //}
            #endregion

            #region Convert class (handles nulls and conversions)
            //int toIntTrue = Convert.ToInt32(true);
            //int toIntFalse = Convert.ToInt32(false);
            //double toDoubleTrue = Convert.ToDouble(true);
            //double toDoubleFalse = Convert.ToDouble(false);
            //string strDate = "12-12-2026 12:01:00";
            //string isoStr = "2026-05-20T15:08:00.000Z";
            //DateTime dt = Convert.ToDateTime(strDate);
            //DateTime dt2 = Convert.ToDateTime(isoStr);

            //Console.WriteLine(toDoubleTrue);
            //Console.WriteLine(toDoubleFalse);
            //Console.WriteLine(dt);
            //Console.WriteLine(dt2);
            #endregion

            #region Parse method (throws exception on failure) and try parse(not exception)

            //string userInput = "4354";
            //int parsedNum;

            //bool success = int.TryParse(userInput, out int parsedNum);

            //if (success)
            //{
            //Console.WriteLine($"Parsed successfully: {parsedNum}");
            //}
            //else
            //{
            //Console.WriteLine("Not parsed!");
            //}


            #endregion

            #region Byte Conversion

            //int num = 123456789;
            //byte[] bytes = ByteConverter.getBytes(num); // this method not available
            #endregion

            // String and string builder

            #region string interpolation
            //string formated = $"With format specifier: {DateTime.Now:yyyy:MM:dd}";
            //Console.WriteLine(formated);
            #endregion

            #region String methods
            /* 
            string str = "sunbeam karad";
            Console.WriteLine(str.Contains("sun"));
            Console.WriteLine(str.ToLower());
            Console.WriteLine(str.ToUpper());
            Console.WriteLine(str.Substring(2, 0));
            Console.WriteLine(str.StartsWith("sun"));
            Console.WriteLine(str.ToCharArray());
            Console.WriteLine(str.IndexOf("beam"));
            */

            //string str = "sunbeam karad";
            //Console.WriteLine(str.Remove(4,1));
            //Console.WriteLine(str.Insert(4, "aaa"));
            //string[] arr = { "Apple", "Katna", "Khana" };
            //Console.WriteLine(string.Join("|", arr));

            // String Comparison
            //int isCompare = string.Compare("ac", "abc");
            //Console.WriteLine(isCompare);
            //if (isCompare == 0) // means true || 1 means false
            //{

            //}


            #endregion

            #region StringBuilder(mutable, better performance for many operations)
            //StringBuilder sb = new StringBuilder();
            //sb.Append("A");
            //sb.Append("B");
            //sb.Append(" ");
            //sb.Append("C a ! a");
            //sb.AppendLine("!"); // new line
            //sb.Append("C a ! a");
            //Console.WriteLine(sb);
            #endregion


            #region String interpolation vs String format

            // old way
            //Console.WriteLine(string.Format("Name: {1}, Age: {0}", 13, "Akram"));
            // new way
            //Console.WriteLine($"Name: {"Akram"}: Age: {13}");

            #endregion

            #region Get typw uing switch
            //object value = new A();
            //switch (value)
            //{
            //    //case int i when i > 50:
            //        //Console.WriteLine($"Large int: {i}");
            //        //break;
            //    case int i:
            //        Console.WriteLine($"Int: {i}");  // 42 matches here
            //        break;
            //    case string s:
            //        Console.WriteLine($"String: {s}");
            //        break;
            //    case null:
            //        Console.WriteLine("Null value");
            //        break;
            //}
            //object value = new B();
            //switch (value)
            //{
            //    case A a:
            //        Console.WriteLine("A");
            //        break;
            //    case B b:
            //        Console.WriteLine("B");
            //        break;
            //}

            /* [FOCUS] */
            // Suntax error I am currently using 7.3 but this feature available at 9.0 or greater.
            //int score = 10;
            //string result = score switch
            //{
            //    >= 90 => "A",
            //    >= 80 => "B",
            //    >= 70 => "C",
            //    >= 60 => "D",
            //    _ => "F"
            //};

            //string[] arr = { "Akram", "Bakram", "Chakram" };
            //foreach(string a in arr){
            //    Console.WriteLine($"char: {a}");
            //}

            #endregion

            #region Method and Perameter
            // default: Console.WriteLine("Nothing");
            //int substract(int a, int b) => a - b;

            //bool tryDivide(int num, int dominator, out int result)
            //{
            //    if(dominator == 0)
            //    {
            //        result = 0;
            //        return false;
            //    }

            //    result = num / dominator;

            //    return true;
            //}

            //bool isDivided = tryDivide(20, 0, out int res);
            //if (isDivided)
            //{
            //    Console.WriteLine($"result: {res}");
            //}
            //else
            //{
            //    Console.WriteLine("is not divided");
            //}

            // OUT -> write only reference
            // IN -> Read only reference
            // ref -> Read/Write reference

            #endregion

            #region Method and Perameter (IN, OUT, REF, PARAMS, etc)

            // in example
            //void inExample(in MyStruct s) // we cannot change struct field using in
            //{
            //    s.x = 10;
            //}
            //void inExample(in MyClass s) // we cannot change struct field using in
            //{
            //    s.X = 20;
            //}
            //another example

            //MyClass myClass = new MyClass();
            //myClass.X = 10;
            //inExample(myClass);

            //Console.WriteLine(myClass.X); // not use in keyword in this


            // PARAMS
            //void paramsExample(params int[] strs)
            //{

            //}

            //paramsExample(10, 20, 30);

            /* NAMED AND OPTIONAL PARAMETERS */
            //void createUser(string name, string email, int age)
            //{
            //    Console.WriteLine($"Name: {name}, Email: {email}, Age: {age}");
            //}

            //createUser(name: "Akram", age: 21);

            #endregion

        }

    }
}
