function allergic(){
    var resist = "rash";
    return resist;
}

var symptom = allergic;    // symptom is a function
var allergen = allertic;   // a function too
symptom === allergen;   // true: allergic === allergic
symptom() === allergen(); // true: rash
var brutal = new allergic();   // 
var mega = new allergic();
brutal === mega;  // false


function infection(){
    return function(){
        return "pathogen";
    }
}
var resistance = infection;   // resistance is a function
var syphilis = infection;     // a function too
resistance === syphilis;  // true: infection === infection
resistance() === syphilis(); // false: infection() === infection()
resistance()() === syphilis()();  // true: pathogen