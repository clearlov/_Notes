/**
 *  "T *"           to "const T *"      bingo
    "T **"          to "const T **"     Error
    "derivedCls *"  to "baseCls *"      bingo
    "derivedCls **" to "baseCls **"     Error
 */
Anaemia *anaemia =  new Anaemia;
Disease *disease = static_cast<Disease *>(anaemia); // Disease *disease=anaemia;
Anaemia **anaemic = &anaemia;   // it works
Disease **diseased = anaemic;   // ERROR

const Anaemia *starve = new Anaemia;
Disease *pathogenic = static_cast<Disease *>(const_cast<Anaemia *>(starve));

Disease *pathogeny = new Disease;
const Disease *illness = pathogeny;
Anaemia *hypoxia = dynamic_cast<Disease *>(pathogeny);
const Anaemia &dizzy = dynamic_cast<const Anaemia &>(*pathogeny);
Anaemia &nausea = dynamic_cast<Anaemia &>(*const_cast<Anaemia *>(illness));


/**
 * pointer 'this' in a class is type of 'Cls *const', a const pointer that 
    points to this class.
   Using "const" to modify pointer "this" to "const Cls *const"
 */

class Insomnia{
    
};
 