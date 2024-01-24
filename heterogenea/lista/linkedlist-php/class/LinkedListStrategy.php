<?php 

namespace Lista\class;

use Lista\class\Node;

abstract class LinkedListStrategy{

    protected Node|null $head;

    protected Node|null $tail;

    public function __construct()
    {

        $this->head = null;
        
        $this->tail = null;
        
    }

    abstract public function addHead(mixed $value) : void;

    abstract public function addTail(mixed $value) : void;
    
    abstract public function addIndex(int $index, mixed $value) : void;

    abstract public function popHead() : void;

    abstract public function popTail() : void;

    abstract public function popIndex(int $index) : void;

    abstract public function getIndex(int $index) : Node|null;

    abstract public function getHead() : Node|null;

    abstract public function getTail() : Node|null;

    abstract public function contains() : bool;

    abstract public function size() : int;

}


?>