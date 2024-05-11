// 1.Ways to print
console.log("Hello world");

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
    // 1.Primitive datatype: Undefined,null,number,string,boolen,symbol
    // 2.Reference datatype: Arrays,objects
                
            // 1.PRIMITIVE
                // a.Numbers
                    var num1=34;
                    var num2=56;
                    console.log(num1+num2);

                // b.Strings
                    var str1="This is a string";
                    var str2='This is , also a string';
                    console.log(str1+",",str2);
                    // Template string
                    console.log(`Hey ${str1}`)

                    // Using its length
                    console.log(str1.length)

                    // Changing its case
                    console.log(str1.toUpperCase())

                    // Using substring
                    console.log(str1.substring(0,8))

                    // Spliting
                    console.log(str2.split(','))                    

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
                    //Adding
                    console.log(array[1])
                    array[5]='astu'
                    console.log(array);

                    //Pop
                    array.pop()
                    console.log(array);
                    
                
                // b.Objects
                    var marks={
                        ravi:34,
                        astu:99,
                        harry: 78,
                        array:[1,2,"bablu",4,5],
                    }
                    
                    console.log(marks.array[2]);

                    // Adding to object
                    marks.deev=99;
                    console.log(marks)

                // ARRAY OF OBJECTS
                const todo=[
                        {
                            id:1,
                            text:'Hey',
                            completed:true
                        },
                        {
                            id:2,
                            text:'How you doing',
                            completed:true
                        },  
                        {   
                            id:3,
                            text:'Alright',
                            completed:false
                        }   
                            ];


//4. FOR LOOPS
for(let i=0;i<5;i++)
    {
        console.log(i);
    }
for(let i=0;i<todo.length;i++)
    {
        console.log(todo[i].text);
    }



// 5.While loop
let j=0
while(j<10)
    {
        console.log(j);
        j++;
    }


// 6.Filter
const todocompleted=todo.filter(function(todo){
    return todo.completed==true
})
console.log(todocompleted)


            

        