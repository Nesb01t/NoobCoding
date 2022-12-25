<template>
  <div class="app">
    <div class="hello">{{ hello }}</div>
    <div class="price">{{ githubPrice }}</div>
    <button @click="handleClick()">Button</button>
  </div>
</template>

<script setup>
import { ref } from "vue";
import { storeToRefs } from 'pinia'
import { usePriceStore } from "@/stores/price.js";

const priceStore = usePriceStore();
const { githubPrice } = storeToRefs(priceStore)

const hello = ref(1);

const handleClick = () => {
  priceStore.addPrice()
  hello.value++;
};
</script>
