let inputs= document.querySelectorAll("input");
let form = document.querySelector("form");
let blockCard= document.querySelector("#blockCard");
form.addEventListener("submit",function(det){
    det.preventDefault();
  /* for (let index = 0; index <4; index++) {
    inputs[index].value="";
    
   }*/
 

  let card = document.createElement("div");
  card.classList.add("card");
  blockCard.appendChild(card);

  let profile_pic = document.createElement("div");
  profile_pic.classList.add("profile_pic");
  card.appendChild(profile_pic);

  let img = document.createElement("img");
   img.setAttribute("src",inputs[0].value);
  img.setAttribute("alt",inputs[0].value);
  profile_pic.appendChild(img);

  let h3 = document.createElement("h3");
  card.appendChild(h3);
  h3.textContent= inputs[1].value;

   let h5 = document.createElement("h5");
  card.appendChild(h5);
  h5.textContent= inputs[2].value;

  let p = document.createElement("p");
  card.appendChild(p);
  p.textContent= inputs[3].value;

   inputs.forEach(x => {
    if(x.type!=="submit")
      x.value="";
  });
})


