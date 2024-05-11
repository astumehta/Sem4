const form=document.getElementById('form')
const username=document.getElementById('username')
const email=document.getElementById('email')
const password=document.getElementById('password')
const password2=document.getElementById('password2')

form.addEventListener('submit',e=>{
    e.preventDefault();
    validateinput();
});
const setError =(element,message)=>{
    const inputcontrol=element.parentElement;
    const errorDisplay=inputcontrol.querySelector('.error');

    errorDisplay.innerText=message;
    inputcontrol.classList.add('error');
    inputcontrol.classList.remove('success');
    

}
const setSuccess=element=>{
    const inputcontrol=element.parentElement;
    const errorDisplay=inputcontrol.querySelector('.error');
    errorDisplay.innerText='';
    inputcontrol.classList.add('success');
    inputcontrol.classList.remove('error');
}
const validateinput=() =>{
    const usernamevalue=username.value.trim();
    const emailvalue=email.value.trim();
    const passwordvalue=password.value.trim();
    const password2value=password2.value.trim();

    if(usernamevalue==='')
        {
            setError(username,"Username is empty");
        }
    else
        {
            setSuccess(username);
        }
}