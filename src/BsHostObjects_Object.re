
module Proto = (T: {
  type t('a);
  type constructor('a);
  type prototype('a);
}) => {
  [@bs.get] external prototype: T.t('a) => T.prototype('a) = "prototype";
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

type t('a)
type constructor('a);
type prototype('a);
type globalObject;
[@bs.val] external globalObject: globalObject = "Object";

include Proto({
  type nonrec t('a) = t('a);
  type nonrec constructor('a) = constructor('a);
  type nonrec prototype('a) = prototype('a);
});

[@bs.val] external make: unit => t('a) = "Object";
[@bs.val] [@bs.scope "Object"] external assign: (t({..}), t({..})) => t({..}) = "assign";
[@bs.val] [@bs.scope "Object"] external assign2: (t({..}), t({..}), t({..})) => t({..}) = "assign";
[@bs.val] [@bs.scope "Object"] external assign3: (t({..}), t({..}), t({..}), t({..})) => t({..}) = "assign";
[@bs.val] [@bs.scope "Object"] external freeze: t('a) => t('a) = "freeze";
[@bs.val] [@bs.scope "Object"] external create: t('a) => t('b) = "create";
[@bs.val] [@bs.scope "Object"] external createWithPropertyDescriptors: (t('a), BsHostObjects_PropertyDescriptor.t('b)) => t('b) = "create";
[@bs.val] [@bs.scope "Object"] external defineProperty: (t('a), string, BsHostObjects_PropertyDescriptor.t('b)) => t('b) = "defineProperty";

/** 
 * `defineProperties` is highly polymorphic and cannot be type-checked.
 * Prefer using `defineProperty` multiple times instead.
 */
[@bs.val] [@bs.scope "Object"] external defineProperties: (t('a), Js.t({..})) => t('b) = "defineProperties";
[@bs.val] [@bs.scope "Object"] external is: (t('a), t('a)) => bool = "is";
[@bs.val] [@bs.scope "Object"] external keys: t('a) => array(string) = "keys";
