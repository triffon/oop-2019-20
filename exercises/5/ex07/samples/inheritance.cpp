/*

Основен клас -----> Производен клас -----> Производен клас

*/


class base1 {

};

class base2 {

};

class base3 {

};

class der : public base1, base2, base3 {

};

/*
    public, private и protected

атрибут      | компонента   | в производен
за област    | на основен   | клас
------------------------------------------
public        private         private
              public          public
              protected       protected
private       private         private
              public          private
              protected       private
protected     private         private
              public          protected
              protected       protected

*/

/*
    достъп
    ПД - пряк достъп
    ВД - външен достъп

компонента | производен public | производен private | производен protected
базов      |                   |                    |
--------------------------------------------------------------------------
public     | ПД ВД             | ПД                 | ПД
protected  | ПД                | ПД                 | ПД
private    | -                 | -                  | -

*/

