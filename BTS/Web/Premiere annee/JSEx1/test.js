function majPara(){
    
    str = document.getElementById("name").value;
    document.getElementById("oui").textContent = str;
    
}

function helloPage(){
    str = "Bienvenue sur la page";
    str = str.fontcolor("blue");
    str = "<text_align=\"center\">" + str + "</text_align>";
    document.getElementById("oui").innerHTML = str;
}