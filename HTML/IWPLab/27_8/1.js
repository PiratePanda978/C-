var form = document.getElementById("form1");
var UserID = document.getElementById("UserID");
var Pwd = document.getElementById("Pwd");
var Name = document.getElementById("Name");
var Address = document.getElementById("Address");
var ZIP = document.getElementById("ZIP");
var emailID = document.getElementById("emailID");
var sex = document.getElementById("radio1");
var lang = document.getElementById("check1");
form.addEventListener('submit', (e) => {
    e.preventDefault();
    checkInputs();
});
function checkInputs(){
    var idValue = UserID.value.trim();
    var pwdValue = Pwd.value.trim();
    var nameValue = Name.value.trim();
    var zipValue = ZIP.value.trim();
    var emailValue = emailID.value.trim();
    if(idValue.length<5||idValue.length>12||idValue===''||idvalue===null){
        setError(UserID,'Required and between length 5 and 12');
    }
    if(pwdValue.length<7||pwdValue.length>12||pwdValue.length===0||pwdValue==null){
        setError(Pwd,'Required and between length 7 and 12');
    }
    if(idValue.length<5||idValue.length>12||idValue.lenght===0||idValue==null){
        setError(UserID,'Required and between length 5 and 12');
    }
    if(!/^[a-z]+$/i.test(nameValue)||nameValue.length===0||nameValue==null){
        setError(Name,'Required and letters only.');
    }
    if(!/^\d+$/.test(zipValue)||zipValue==null){
        setError(ZIP,'Required and numbers only.');
    }
    if(!/^(([^<>()[\]\\.,;:\s@\"]+(\.[^<>()[\]\\.,;:\s@\"]+)*)|(\".+\"))@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\])|(([a-zA-Z\-0-9]+\.)+[a-zA-Z]{2,}))$/.test(emailValue)||emailValue==null){
        setError(emailID,'Required and must be a vaid email');
    }
    if(!isOneChecked()){
        setError(sex,"required");
    }
    if(!isOneChecked2()){
        setError(lang,"required");
    }
}

function setError(input,message){
    var formControl = input.parentElement;
    var small = formControl.querySelector('small');
    small.innerText = message;
    formControl.className = 'error';
}

function isOneChecked() {
    var chx = document.getElementsByTagName('input');
    for (var i=0; i<chx.length; i++) {
      if (chx[i].type == 'radio' && chx[i].checked) {
        return true;
      } 
    }
    return false;
  }

  function isOneChecked2()
{
    var checkboxs=document.getElementsByName("Language");
    for(var i=0;i<checkboxs.length;i++)
    {
        if(checkboxs[i].checked)
        {
            return true;
        }
    }
    return false;
}