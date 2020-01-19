let i = 0;
let current_mode = 1;
document.getElementById("Signer").style.display = "none";
function myFunction(){
    if(current_mode) {
        document.getElementById("Speaker").style.display = "block";
        document.getElementById("Signer").style.display = "none";
        document.getElementById("clickMe").innerHTML = "Switch to Signer Mode";
        current_mode = 0;
    }
    else{
        document.getElementById("Speaker").style.display = "none";
        document.getElementById("Signer").style.display = "block";
        document.getElementById("clickMe").innerHTML = "Switch to Speaker Mode";
        current_mode = 1;
    }
}
document.getElementById("clickMe").onclick = myFunction;
