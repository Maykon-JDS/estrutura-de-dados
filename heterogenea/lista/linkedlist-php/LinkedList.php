<?php 

require_once "Node.php";

class LinkedList {

    protected Node $root;

    public function __construct(int $value)
    {
        
        $newNode = new Node($value);

        $this->root = $newNode;

    }

    public function push(int $value) : void
    {
        $node = $this->root;

        $newNode = new Node($value);

        while($node->getPos() != null){

            $node = $node->getPos();
            
        }

        $newNode->setPrev($this->root);

        $node->setPos($newNode);

    }

    public function __toString() : string
    {
        $node = $this->root;

        $result = "[";
        
        while($node != null){

            $result .=  $node->getValue();

            if($node->getPos() != null){

                $result .= ", ";

            }

            $node = $node->getPos();
            
        }

        $result .= "]";

        return $result;

    }

}

$linkedlist = new LinkedList(10);

$linkedlist->push(5);
$linkedlist->push(8);
$linkedlist->push(10);
$linkedlist->push(30);
$linkedlist->push(2);
$linkedlist->push(3);

echo $linkedlist;

?>