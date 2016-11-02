class Parent {
  proc clone() : Parent {
    writeln("in Parent.clone()");
    return nil;
  }
}

class Child : Parent {
  proc clone() : Parent {
    writeln("in Child.clone()");
    return new Child();
  }
}



record R {
  var obj:Parent = nil;
}

pragma "donor fn"
pragma "auto copy fn"
proc chpl__autoCopy(arg: R) {

  // TODO - is no auto destroy necessary here?
  pragma "no auto destroy"
  var ret: R;

  writeln("autoCopy");

  ret.obj = arg.obj.clone();

  return ret;
}

// I'd like this to be ref, but that breaks
//    var outerX: R; begin { var x = outerX; }
pragma "init copy fn"
proc chpl__initCopy(arg: R) {
  // TODO - is no auto destroy necessary here?
  pragma "no auto destroy"
  var ret: R;

  writeln("initCopy");

  ret.obj = arg.obj.clone();

  return ret;
}

proc doAutoCopyIt(x)
{
  return x;
}
proc main() {
  var r = new R(new Child());
  writeln(doAutoCopyIt(r));
}
