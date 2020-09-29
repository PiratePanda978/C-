function changeAll(){
    var heading = document.getElementById("heading");
    heading.innerHTML = "Heading after DOM";
    heading.style = "color : blue";
    var paragraph = document.getElementById("Paragraph");
    paragraph.innerHTML = "Impelementation of DOM manipulation for inserting content in html element.";
    document.getElementById("paragraph1").setAttribute("class","change");
    var para = document.createElement("p");
    var node = document.createTextNode("This element has been inserted using dom");
    para.appendChild(node);
    document.getElementById("div1").appendChild(para);
}

function remove(){
    var ls = document.getElementById("list");
    ls.removeChild(ls.childNodes[1]);
}

function mOver(obj){
    obj.innerHTML = "After mouse hover.";
}

function mOut(obj){
    obj.innerHTML = "Before mouse hover.";
}

function whichKey(event){
    var x = event.key;
    document.getElementById("paragraph2").innerHTML = "The key pressed was : "+x;
}