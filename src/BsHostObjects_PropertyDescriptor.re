type t('a) = {
  .
  "value": 'a,
  "writable": bool,
  "enumerable": bool,
  "configurable": bool,
  "get": Js.Undefined.t(unit => 'a),
  "set": Js.Undefined.t('a => unit),
};

[@bs.obj] external make: (
  ~value:'a=?,
  ~writable: bool=?,
  ~enumerable: bool=?,
  ~configurable: bool=?,
  ~get: unit => 'a=?,
  ~set: 'a => unit=?,
) => t('a) = "";
