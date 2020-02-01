
module ConstructorAny = (T: {
  type t('a)
  type constructor('a);
}) => {
  [@bs.get] external constructor: T.t('a) => T.constructor('a) = "constructor";
};
