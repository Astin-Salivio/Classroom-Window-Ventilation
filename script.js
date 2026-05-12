/* ================= LOGIN ================= */

function login(){

  const username =
  document.getElementById("username");

  const password =
  document.getElementById("password");

  if(username && password){

    if(username.value === "" || password.value === ""){

      alert("Please fill in all fields.");

    }

    else{

      alert("Login Successful!");

      window.location.href = "main.html";

    }

  }

}

/* ================= SETTINGS ================= */

const settingsPanel =
document.getElementById("settingsPanel");

function toggleSettings(){

  if(settingsPanel){

    settingsPanel.classList.toggle("active");

  }

}

/* ================= DARK MODE ================= */

function toggleDarkMode(){
  document.body.classList.toggle("dark-mode");
}

/* ================= LOGOUT ================= */

function logout(){
  window.location.href = "login.html";
}

/* ================= NOTIFICATIONS ================= */

const notificationPanel =
document.getElementById("notificationPanel");
const infoPanel =
document.getElementById("infoPanel");

function openNotifications(){

  if(notificationPanel){

    notificationPanel.classList.add("active");

  }

}
function openInfo(){

  if(infoPanel){

    infoPanel.classList.add("active");

  }

}

function closeInfo(){

  if(infoPanel){

    infoPanel.classList.remove("active");

  }

}
function closeNotifications(){

  if(notificationPanel){

    notificationPanel.classList.remove("active");

  }

}