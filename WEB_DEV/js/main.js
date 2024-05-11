// 1.Ways to print
console.log("Hello world");
document.write("This is document write");

// 2.Javascript console API
console.log("Hello world",4+6,"Another log");
console.warn("This is a warning");
console.error("This is an error");

// 3.Variables
var number1=34;
var number2=56;
console.log(number1+number2);
// Data types--->>>
// There are 2 types of data types-
    // 1.Primitive datatype: Undefined,null,number.string,boolen,symbol
    // 2.Reference datatype: Arrays,objects
                
            // 1.PRIMITIVE
                // a.Numbers
                    var num1=34;
                    var num2=56;
                    console.log(num1+num2);

                // b.Strings
                    var str1="This is a string";
                    var str2='This is also a string';
                    console.log(str1+",",str2);

                // c.Booleans
                    var a=true;
                    var b=false;
                    console.log(a,b);
                
                // d.Undefined
                    var un;
                    console.log(un);
            
            // 2.REFERENCE
                
                // a.Array
                    var array=[1,2,"bablu",4,5];
                    console.log(array);
                
                // b.Objects
                    var marks={
                        ravi:34,
                        astu:99,
                        harry: 78,
                    }
                    console.log(marks);
            

        