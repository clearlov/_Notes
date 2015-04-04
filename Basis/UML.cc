/**
 * @see http://en.wikipedia.org/wiki/Class_diagram
 *  + public
 *  - private
 *  # protected
 *  / derived
 *  ~ package
 * @note relationship from estrangement to inseparable
 *  Dependency < Association < Aggregation < Composition
 */

 
 
 
class Juvenile   // ['dʒuːvənaɪl]
{ 
  /**
   * Association
   *  Juvenile has Tutors, Friends ...
   */
  list<Tutor> tutor; // Juvenile -1-*-> Tutor
  /**
   * Aggregation: variant "has a" association relationship
   *  Juvenile is made up with adults(Men and women)
   */
  Menfolk men;            // Juvenile <>-1-1-> Menfolk
  Women feminine[4];     // Juvenile <>-1-4-> Women
}

class Digest
{
  virtual void drain() = 0;
}


class Digestive: public Juvenile,  // Generalization:  Digestive extends Juvenile
                 public Digest  // Realization:     Digestive implements Digest
{
  public:
  /**
   * Dependency: 
   *  you can digest Legume, Fruit ..., any food.
   */
  void digest(Legume legume); // Digestive ~~digest~~> Legume
  /**
   * Composition: stronger variant "has a" association relationship, inseparable
   *  Without Digestive, Intestine, Stomach are worthless, they can't exist inde
   *  -pendent.
   */
  Intestine Intestine;          // Digestive <#>-1-1-> Intestine
  Stomach stomach[3];         // Digestive <#>-1-3-> Stomach
}