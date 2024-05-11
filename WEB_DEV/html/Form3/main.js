
function getvalidate() {
    var name = document.getElementById("name").value.trim();
var email = document.getElementById("email").value.trim();
var password = document.getElementById("password").value.trim();
var phone = document.getElementById("phone").value.trim();
var address = document.getElementById("address").value.trim();
var dob = document.getElementById("dob").value.trim();
var message = document.getElementById("msg");
  var phoneNumberPattern = /^[0-9]{10}$/;
  var emailPattern = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
  var passwordPattern = /^(?=.*[!@#$%^&*])[a-zA-Z0-9!@#$%^&*]{8,}$/;

  var errorMsg = "";

  if (name === "") {
    errorMsg += "Empty field: Name\n";
  }

  if (dob === "") {
    errorMsg += "Empty field: Date of Birth\n";
  }

  if (address === "") {
    errorMsg += "Empty field: Address\n";
  }

  if (!phoneNumberPattern.test(phone)) {
    errorMsg += "Invalid Phone number\n";
  }

  if (!emailPattern.test(email)) {
    errorMsg += "Invalid Email\n";
  }

  if (!passwordPattern.test(password)) {
    errorMsg +=
      "Password must be at least 8 characters long and contain at least one special character\n";
  }

  if (errorMsg !== "") {
    alert(errorMsg);
    return false;
  } else {
    message.innerHTML = "FORM SUBMITTED";
  }

  return true;
}
function getclear() {
    document.getElementById("name").value = "";
    document.getElementById("email").value = "";
    document.getElementById("password").value = "";
    document.getElementById("phone").value = "";
    document.getElementById("address").value = "";
    document.getElementById("dob").value = "";
    document.getElementById("msg").innerHTML = "";
}

