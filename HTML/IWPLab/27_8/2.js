var form = document.getElementById("form1");
var fname = document.getElementById("fname");
var lname = document.getElementById("lname");
var Mobile = document.getElementById("Mobile");
var city = document.getElementById("city");
var ZIP = document.getElementById("ZIP");
var state = document.getElementById("state");
form.addEventListener('submit', (e) => {
    e.preventDefault();
    checkInputs();
});
function checkInputs(){
    var fnameValue = fname.value.trim();
    var lnameValue = lname.value.trim();
    var mobileValue = Mobile.value.trim();
    var zipValue = ZIP.value.trim();
    var cityValue = city.value.trim();
    var stateValue = state.value.trim();
    if(fnameValue.length>30||fnameValue==null||!/^[a-z]+$/i.test(fnameValue)){
        setError(fname,'Max 30 characters a to z');
    }
    if(lnameValue.length>30||lnameValue==null||!/^[a-z]+$/i.test(lnameValue)){
        setError(lname,'Max 30 characters a to z');
    }
    if(!/^\d+$/.test(mobileValue)||mobileValue==null||mobileVlaue.length>10){
        setError(Mobile,'10 digit number.');
    }
    if(!/^[a-z]+$/i.test(cityValue)||cityValue.length>30||nameValue==null){
        setError(city,'Max 30 characters a to z');
    }
    if(!/^\d+$/.test(zipValue)||zipValue==null||zipValue.length>6){
        setError(ZIP,'6 digit number');
    }
    if(!/^[a-z]+$/i.test(stateValue)||stateValue.length>30||stateValue==null){
        setError(state,'Max 30 characters a to z');
    }
}

function setError(input,message){
    var formControl = input.parentElement;
    var small = formControl.querySelector('small');
    small.innerText = message;
    formControl.className = 'form-control error';
}