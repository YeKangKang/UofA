var index = 0;
function mcount() {
    var m = document.getElementById("mcount");
    index++;
    m.innerHTML = index;
}

function post(){
// get num of posts
    var num = document.getElementsByName("quantity")[0].value;

// create post obj
    let post = {
        content: document.getElementsByTagName("textarea")[0].value,
        date: new Date()
    };

// add num of new posts as new div
    for (i=0; i<num; i++){
        let newpost = document.createElement("DIV");
        newpost.innerHTML = `<div class="posted">
            <p class="post-time"><b>${post.date}</b></p>
            <p class="post-content">${post.content}</p>
        </div>`;

    // text color button & Bold & Italic
        var blue = document.getElementsByName("color")[0].checked;      // Blue Button
        var red = document.getElementsByName("color")[1].checked;       // Red Button
        var bold = document.getElementsByName("style")[0].checked;      // Bold Button
        var italic = document.getElementsByName("style")[1].checked;     // Itlic Button

        if (blue === true){
            newpost.style.color = "blue";
        }else if (red === true) {
            newpost.style.color = "red";
        }
        if (bold === true && italic === false) {
            newpost.style.fontWeight = "bold";
        }else if (italic === true && bold === false) {
            newpost.style.fontStyle = "italic";
        }else if (italic === true && bold === true) {
            newpost.style.fontWeight = "bold";
            newpost.style.fontStyle = "italic";
        }
        document.getElementById("posts").appendChild(newpost);          // Add new div to list
    }
}

function displayMenu() {
    // get Menu ID
    var menu = document.getElementById("menu");
    // get Main ID
    var main = document.getElementById("main");

    // hide main display menu
    main.style.display = "none";
    menu.style.display = "block";
}

function displayMain() {
    // get Menu ID
    var menu = document.getElementById("menu");
    // get Main ID
    var main = document.getElementById("main");

    // hide menu display main
    main.style.display = "block";
    menu.style.display = "none";
}

function changeBackGroundColor() {
// get input
    var color = document.getElementById("background").value;
// change body style
    document.getElementsByTagName("body")[0].style.background = color;
}

function bar() {
    // get bar value
    var bar = document.getElementsByName("visible")[0].value;
    // get num of posted item
    var num = document.getElementsByClassName("posted").length;

    // get posted div
    var arr = document.getElementsByClassName("posted");

    for (i=0; i<num; i++) {
        if (i < bar){
            arr[i].style.display = "block";
        }else {
            arr[i].style.display = "none";
        }
    }
}