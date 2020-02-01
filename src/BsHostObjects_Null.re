module Impl = (T: {
  type t('a);
}) => {

  // Empty for now;
};

type null = Js.Types.null_val;

type t('a) = Js.null('a);

let empty: t(null) = Js.Null.empty;
