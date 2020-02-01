
module Impl = (T: {
  type t('a);
  type constructor('a);
}) => {

  [@bs.get] external constructor: T.t('a) => T.constructor('a) = "constructor";
  [@bs.send] external constructorWithValue: (T.t('a), 'b) => T.t('b) = "constructor";
  [@bs.send] external __defineGetter__: (T.t('a), string, unit => 'value) => 'value = "__defineGetter__";
  [@bs.send] external __defineSetter__: (T.t('a), string, 'value => unit) => unit = "__defineSetter__";
  [@bs.send] external hasOwnProperty: (T.t('a), string) => bool = "hasOwnProperty";
  [@bs.send] external isPrototypeOf: (T.t('a), T.t('b)) => bool = "isPrototypeOf";
  [@bs.send] external propertyIsEnumerable: (T.t('a), string) => bool = "propertyIsEnumerable";
  [@bs.send] external toLocaleString: T.t('a) => string = "toLocaleString";
  [@bs.send] external toString: T.t('a) => string = "toString";
  [@bs.send] external valueOf: T.t('a) => 'a = "valueOf";
  [@bs.send] external seal: T.t('a) => unit = "seal";
  [@bs.send] external setPrototypeOf: (T.t('a), T.t('b)) => unit = "setPrototypeOf";
  [@bs.send] external getPrototypeOf: (T.t('a), T.t('b)) => unit = "getPrototypeOf";
};

type t('a) = Js.t('a)
type constructor('a);

include Impl({
  type nonrec t('a) = t('a);
  type nonrec constructor('a) = constructor('a);
});

[@bs.new] external make: unit => t('a) = "Object";

[@bs.val] [@bs.scope "Object"] external assign: (t('a), t('b)) => t('c) = "assign";
[@bs.new] [@bs.scope "Object"] external constructor: 'a => t('a) = "constructor";
