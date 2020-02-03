module Constructor = (T: {
  type t
  type constructor;
}) => {
  [@bs.get] external constructor: T.t => T.constructor = "constructor";
};

module ConstructorAny = (T: {
  type t('a)
  type constructor('a);
}) => {
  [@bs.get] external constructor: T.t('a) => T.constructor('a) = "constructor";
};

module Function_Proto_Call = (T: {
  type t('a);
}) => {
  [@bs.send] external call: T.t('ty) => 'z = "call";
  [@bs.send] external call1: (T.t('ty), 'a) => 'z = "call";
  [@bs.send] external call2: (T.t('ty), 'a, 'b) => 'z = "call";
  [@bs.send] external call3: (T.t('ty), 'a, 'b, 'c) => 'z = "call";
  [@bs.send] external call4: (T.t('ty), 'a, 'b, 'c, 'd) => 'z = "call";
  [@bs.send] external call5: (T.t('ty), 'a, 'b, 'c, 'd, 'e) => 'z = "call";
  [@bs.send] external call6: (T.t('ty), 'a, 'b, 'c, 'd, 'e, 'f) => 'z = "call";
  [@bs.send] external call7: (T.t('ty), 'a, 'b, 'c, 'd, 'e, 'f, 'g) => 'z = "call";
  [@bs.send] external call8: (T.t('ty), 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h) => 'z = "call";
  [@bs.send] external call9: (T.t('ty), 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i) => 'z = "call";
  [@bs.send] external call10: (T.t('ty), 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i, 'j) => 'z = "call";
};

module Function_Proto_Apply = (T: {
  type t('a);
}) => {
  [@bs.send] external apply: (T.t('ty), array('a)) => 'z = "apply";
};

module Function_Proto_Bind = (T: {
  type t('a);
}) => {
  [@bs.send] external bind: T.t('ty) => 'z = "bind";
  [@bs.send] external bind1: (T.t('ty), ~ctx: 'ctx, 'a) => 'z = "bind";
  [@bs.send] external bind2: (T.t('ty), ~ctx: 'ctx, 'a, 'b) => 'z = "bind";
  [@bs.send] external bind3: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c) => 'z = "bind";
  [@bs.send] external bind4: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd) => 'z = "bind";
  [@bs.send] external bind5: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd, 'e) => 'z = "bind";
  [@bs.send] external bind6: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd, 'e, 'f) => 'z = "bind";
  [@bs.send] external bind7: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd, 'e, 'f, 'g) => 'z = "bind";
  [@bs.send] external bind8: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h) => 'z = "bind";
  [@bs.send] external bind9: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i) => 'z = "bind";
  [@bs.send] external bind10: (T.t('ty), ~ctx: 'ctx, 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h, 'i, 'j) => 'z = "bind";
};


/**
 * WHAT MADNESS!!
 */

module Function_Proto_Call2 = (T: {
  type t('a);
}) => {
  [@bs.send] external call: (T.t(unit => 'return), 'ctx) => 'return = "call";
  [@bs.send] external call1: (T.t('a => 'return), 'ctx, 'a) => 'return = "call";
  [@bs.send] external call2: (T.t(('a, 'b) => 'return), 'ctx, 'a, 'b) => 'return = "call";
  [@bs.send] external call3: (T.t(('a, 'b, 'c) => 'return), 'ctx, 'a, 'b, 'c) => 'return = "call";
  [@bs.send] external call4: (T.t(('a, 'b, 'c, 'd) => 'return), 'ctx, 'a, 'b, 'c, 'd) => 'return = "call";
  [@bs.send] external call5: (T.t(('a, 'b, 'c, 'd, 'e) => 'return), 'ctx, 'a, 'b, 'c, 'd, 'e) => 'return = "call";
  [@bs.send] external call6: (T.t(('a, 'b, 'c, 'd, 'e, 'f) => 'return), 'ctx, 'a, 'b, 'c, 'd, 'e, 'f) => 'return = "call";
  [@bs.send] external call7: (T.t(('a, 'b, 'c, 'd, 'e, 'f, 'g) => 'return), 'ctx, 'a, 'b, 'c, 'd, 'e, 'f, 'g) => 'return = "call";
  [@bs.send] external call8: (T.t(('a, 'b, 'c, 'd, 'e, 'f, 'g, 'h) => 'return), 'ctx, 'a, 'b, 'c, 'd, 'e, 'f, 'g, 'h) => 'return = "call";
};

module ExtendCall = (T: {
  type t('a);
}) => {
  include Function_Proto_Call2({
    type t('a) = T.t('a);
  });
};

module Test = {
  type t('a);

  [@bs.val] external test: t(int => string) = "test";

  module F1 = Function_Proto_Call2({
    type nonrec t('a) = t('a);
  });

  module F2 = ExtendCall({
    type nonrec t('a) = t('a);
  });
  
  let str = F2.call1(test, {
    "sayHi": () => "hi",
  }, 1);

};



