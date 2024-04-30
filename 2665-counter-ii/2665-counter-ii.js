/**
 * @param {integer} init
 * @return { increment: Function, decrement: Function, reset: Function }
 */
var createCounter = function(init) {
    let count = init;
    return {
      increment : ()=>{
      return ++count;
      },
         reset : ()=>{
            return count = init;
        },
        decrement : ()=>{
           return --count;
        }
       
        
    };
};

/**
 * const counter = createCounter(5)
 * counter.increment(); // 6
 * counter.reset(); // 5
 * counter.decrement(); // 4
 */